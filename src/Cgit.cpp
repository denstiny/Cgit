#include "../include/Cgit.hpp"
#include <cstdlib>
#include <iostream>



CgitWorkCompany::CgitWorkCompany(int argc,string &argv) {
	// 构造函数
	string str,NodeStr;
	int LineNum;
	obs.open((CgitCwd+CgitConf).c_str(),ios::in);
	if(!obs.is_open()) {
		cout << "Error! No configuration file. " << endl;
		exit(1);
	}
	
	CgitConfigRead(str);
	nlohmann::json tempjson = nlohmann::json::parse(str,nullptr,false);
	
	//  NChoose 节点
	if((LineNum = tempjson["NChoose"]) != 0) {
		NodeStr = tempjson["Node"][LineNum-1];
		cout << "Use NChoose node first: " <<  LineNum << endl;
		
		URL = argv;
		if(URL.substr(0,18) == "https://github.com") 
			URL = NodeStr + URL.substr(18);
	} 
	// ReverseNode 节点
	if((LineNum = tempjson["Rreverse"]) != 0) {
		NodeStr = tempjson["ReverseNode"][LineNum-1];
		URL = NodeStr+'/'+argv ;
		cout << "Use Reverse node first: " <<  LineNum << endl;
	}
	//if(argc > 2) {
	//	for(int i = 2;i < argc;i++) 
	//		URL = URL + " " + argv;
	//}
	//cout << URL << endl;
}

bool CgitWorkCompany::CgitConfigRead(string &strk) {
	
	string str = "";
	string tempstr = "";
	while (!obs.eof()) {
		tempstr = obs.get();
		str += tempstr;
		if(tempstr == "}")
			break;
	}
	strk = str;
	return true;
}
// https://github.com/denstiny/code.git 
void CgitWorkCompany::ModifyAddress(int argc,char *argv[]) {
	if(argc == 3) {
		fstream gitconf(argv[2],ios::in | ios::app);
		if(!gitconf.is_open()) {
			gitconf.close();
			return;
		}else if(argc == 2) {
			string ur = argv[1];
			int i=0;
			for(int s = 0;i < 20 && s <= 4;i++) {
				if (*(argv[1]+s) == '/' )
					s++;
			}
			ur.substr(i); // 得出项目地址
		}
	}
}


CgitWorkCompany::~CgitWorkCompany() {
	// 析构函数
}

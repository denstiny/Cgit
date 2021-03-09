#include "../include/Cgit.hpp"
#include <cstdlib>
#include <iostream>



CgitWorkCompany::CgitWorkCompany(int argc,char *argv[]) {
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
		
		URL = argv[1];
		if(URL.substr(0,18) == "https://github.com") {
			URL = NodeStr + URL.substr(18);
//			URL = URL + "  > /dev/null";
		}
	} 
	// ReverseNode 节点
	if((LineNum = tempjson["Rreverse"]) != 0) {
		NodeStr = tempjson["ReverseNode"][LineNum-1];
		URL = NodeStr+'/'+argv[1] ;
	}
	if(argc > 2) {
		for(int i = 2;i < argc;i++) 
			URL = URL + " " + argv[i];
	}
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


CgitWorkCompany::~CgitWorkCompany() {
	// 析构函数
}

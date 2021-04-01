#include "../include/Cgit.hpp"
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>


string Str_Swap(char *str) {
	string file_str;
	return file_str;
}

CgitWorkCompany::CgitWorkCompany(int argc,char *argv[]) {
	// 构造函数
	string str,NodeStr;
	int LineNum;
	EndURl = argv[2];
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
		
		URL = argv[2];
		if(URL.substr(0,18) == "https://github.com") 
			URL =argv[1] + (string)" " + NodeStr + URL.substr(18);
	} 
	// ReverseNode 节点
	if((LineNum = tempjson["Rreverse"]) != 0) {
		NodeStr = tempjson["ReverseNode"][LineNum-1];
		URL = argv[1] + (string)" " + NodeStr+'/'+argv[2] ;
	}
	if(argc > 2) {
		for(int i = 3;i < argc;i++) 
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



// 克隆完毕,修改github的地址
void CgitWorkCompany::ModifyAddress(int argc,char *argv[]) {
	// 取出 文件地址
	string Str_,file_Str;
	cout << argc << endl;
	if(argc > 3)
		file_Str = argv[argc-1];
	if(argc <= 3) {

		int url_s = strlen(argv[argc-1]);

		while (--url_s && argv[2][url_s] != '/') {

			if(Str_ != ".git")	
				Str_.insert(Str_.begin(),argv[2][url_s]);
			else
				file_Str.insert(file_Str.begin(),argv[2][url_s]);
		}
		file_Str = "./"+file_Str;
	}
	file_Str += +"/.git/config"; 

	// 打开文件
	string filetxt_,tempstr_;
	file.open(file_Str.c_str(),ios::in | ios::out);
	if(!file.is_open()) {
		cout << " 打开git 配置文件失败 " << endl;
		cout << " open  " <<  file_Str <<  " error!" << endl;
		return;
	}

	while (!file.eof()) {
		getline(file,tempstr_);
		if(tempstr_.find("url = ") != tempstr_.npos) {
			tempstr_.erase(7);
			tempstr_+=EndURl;
		}
		filetxt_ += tempstr_ + '\n';
	}

	file.close();

	file.open(file_Str,ios::trunc | ios::out);
	file.write(filetxt_.c_str(), filetxt_.size());
	file.close();

}


CgitWorkCompany::~CgitWorkCompany() {
	// 析构函数
}

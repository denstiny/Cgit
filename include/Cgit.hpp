#pragma Cigt_HPP

#include <string>
#include <cstring>
#include <fstream>
#include "../include/json.hpp"
using namespace std;
#define Cgit "git clone "
const string home = getenv("HOME");
const string CgitCwd = home+"/.config/Cgit/";
const string CgitConf = "Cgit.json";
class CgitWorkCompany {
	public:
		fstream obs;
		string URL; // 接受github 仓库链接
		// 创建普通类
		CgitWorkCompany(int argc,char *argv[]);
		~CgitWorkCompany();
		// 提取json数据
		bool CgitConfigRead(string &strk);
		// 处理字符串
};



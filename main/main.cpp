/**
 * File              : main.cpp
 * Author            : denstiny Anonymity <2254228017@qq.com>
 * Date              : 09.03.2021
 * Last Modified Date: 09.03.2021
 * Last Modified By  : denstiny Anonymity <2254228017@qq.com>
 */
/**
 * main/main.cpp
 * Copyright (c) 2021 denstiny Anonymity <2254228017@qq.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include "../include/Cgit.hpp"

void ShowHelp() {
	cout << "-h help" << endl;
	cout << "cgit clone url {address}" << endl;
	exit(0);
}

bool CgitClone(string &url) {
	FILE * fp;
	char buffer[BUFSIZ];
	string Command = Cgit + url;
	fp = popen(Command.c_str(), "r");
	if(fp == NULL) {
		cout << "网络链接失败，请检查网络，或更换节点" << endl;
		pclose(fp);
		return false;
	}
	fgets(buffer ,sizeof(buffer),fp);
	//cout << buffer << endl;
	pclose(fp);
	return true;
}


int main(int argc,char *argv[]) {
	string st;
	if(argc <= 2 || ( st=argv[1]) == "-h") 
		ShowHelp();
	CgitWorkCompany p(argc,argv);
	if (CgitClone(p.URL) == true)
		p.ModifyAddress(argc, argv);
	return 0;
}

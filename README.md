
<!-- vim-markdown-toc GFM -->

* [Cgit 命令行免代理下载工具](#cgit-命令行免代理下载工具)
	* [安装](#安装)
	* [使用](#使用)
	* [配置文件](#配置文件)
		* [节点描述](#节点描述)
	* [代下载网站](#代下载网站)
	* [log](#log)
	* [to do](#to-do)

<!-- vim-markdown-toc -->

# Cgit 命令行免代理下载工具
> 2021-03-09 今天并不是一个好天气，我是刚上大学的新生，受现在的环境影响无法很舒服的使用`git ` 克隆我想要克隆的项目，虽然有很多代下载的网站，但是依旧繁琐，所以他诞生了，祝大家学习之路不用等待  
> qt界面还在制作，命令行版本可以正常使用

> 考虑到被强的只有国内道友，所以就不搞什么英文文档了，省得大家麻烦

## 安装
```
git clone https://github.com/denstiny/Cgit.git
make 
make install
// windows 用户需要手动更改配置文件地址,和makefile文件才能安装
```

## 使用
```sh
克隆到当前目录
cgit clone https://github.com/denstiny/Cgit.git
克隆到指定目录
cgit clone https://github.com/denstiny/Cgit.git /mnt/home/cgit
帮助文档
cgit -h
```
## 配置文件
![20210310012016](https://i.loli.net/2021/03/10/3xvzWkwehTgjK24.png)
配置文件路径为`HOME/.config/Cgit/Cgit.json`
<font size=4><b>默认配置文件</b></font>  
```
	"Node":[
				"https://hub.fastgit.org",
				"https://github.com.cfpmjs"
	],
	"NChoose":1,
	"ReverseNode":[
				"https://gh.api.99988866.xyz",
				"https://ghproxy.com"
	],
	"Rreverse":0,
```
> 以上节点作者如果不想被公开使用请联系我删除  

|节点|作者|  
|:-:|:-:| 
|`https://gh.api.99988866.xyz`|https://github.com/hunshcn/gh-proxy |  
|`https://www.ioiox.com/`|https://www.ioiox.com/ |  
|`https://hub.fastgit.org`|https://fastgit.org |  
|`https://github.com.cfpmjs`|https://chrome.google.com/webstore/detail/github%E5%8A%A0%E9%80%9F/mfnkflidjnladnkldfonnaicljppahpg/related?hl=zh-CN |



`NChoose` 默认为1，选择使用`https://hub.fastgit.org` 节点,0为禁用  
`Rreverse` 默认禁用
### 节点描述
|节点|描述|
|:-|:-:|
|`Node`|镜像节点|
|`ReverseNode`|文件加速节点|

<font size=4><b>如果有无私奉献的道友愿意共享节点，欢迎给我发邮件`2254228017@qq.com`</b></font>  
## 代下载网站 
`https://ednovas.xyz/2021/01/24/githubspeedup/#_2-github%E6%96%87%E4%BB%B6%E5%8A%A0%E9%80%9F`

## log
- <font size=4><b>$date:2021-03-24$</b></font>  
  - 更改使用方法 使用cgit clone与原声git类似，这样可以方便骚操作：
	- 例如：`alias git cgit` 临时使用`cgit` 代替`git`，对其`yay`用户和`vim`用户拷贝插件和应用程序源码有所帮助


## to do 
- ~~自动修正克隆后的项目git配置（有时间在说问题不大）~~
- 自动更换代理
- qt界面工具

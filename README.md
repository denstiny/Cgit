
<!-- vim-markdown-toc GFM -->

* [Cgit 命令行免代理下载工具](#cgit-命令行免代理下载工具)
	* [配置文件](#配置文件)
		* [节点描述](#节点描述)
	* [代下载网站](#代下载网站)
	* [to do](#to-do)

<!-- vim-markdown-toc -->

# Cgit 命令行免代理下载工具
> 2021-03-09 今天并不是一个好天气，我是刚上大学的新生，受现在的环境影响无法很舒服的使用`git ` 克隆我想要克隆的项目，虽然有很多代下载的网站，但是依旧繁琐，所以他诞生了，这也是我的第一个`Qt`项目，祝大家学习之路不用等待  
> qt界面还在制作，命令行版本可以正常使用

> 考虑到被强的只有国内道友，所以就不搞什么英文文档了，省得大家麻烦

## 配置文件
![20210310000101](https://i.loli.net/2021/03/10/3hvZxRIAybiWEBk.png)
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
## to do 
- 自定修改克隆后的项目git配置（有时间在说问题不大）
- 自动更换代理
- qt界面工具

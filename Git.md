# Git基本操作命令
## 安装GIT工具
```shell
sudo apt-get install git
```
## 创建版本库
创建一个用来存放仓库的目录，执行git init命令，创建git仓库
```shell
mkdir html
cd html
git init
```
创建成功后使用ls -al命令查看仓库中文件，有隐藏的.git目录，注意这存放着git管理工具用到的所有信息和基本配置信息，不可手动修改，否则会破坏仓库
## 提交文件
当前目录暂无文件，先创建一个文件README，对其进行编辑
```shell
touch README
vim README
```
查看仓库状态，红色表示未添加，绿色表示已添加
```shell
git status
```
将其添加进仓库
```shell
git add README
git add . //注意这是将当前目录所有文件全部添加进仓库
```
提交到仓库里进行保存
```shell
git commit //需要填写记录日志文档，注意应简洁明了的描述提交的该文件
```
## 配置用户信息
配置用户名, 一般为注册的GitHub用户名
```shell
git config --global user.name
```
配置用户邮箱, 一般为和GitHub绑定的最常用的邮箱
```shell
git config --global user.email
```
配置编辑提交信息的编辑器vim
```shell
git config --global core.editor vim
```
## 查看提交信息
```shell
git log //查看提交的文件日志信息
```
## 删除文件恢复
有时候, 我们不小心把文件给删除了. 想恢复这个文件时, 需要用到下面的命令.

把仓库里的README这个文件给删除了. 然后再使用ls命令查看文件, 看看这个文件是否还存在.
```shell
rm README
ls
ls -al
```
查看仓库状态
```shell
git status
```
发现这个文件是误删了, 我们想把它恢复回来, 如果没有将这个文件提交到仓库里, 无法将它恢复.
```shell
git checkout README
```
再查看文件是否存在，并查看仓库状态
```shell
ls -al
git status
```
只要将文件提交到仓库中，便可对其进行恢复，提交之前需要

# MySQL 关系型数据库
## 更新源
#### 用vim打开源列表文件
sudo vim /etc/apt/sources.list
#### 将下面的源粘贴到源列表里

```shell
deb http://mirrors.aliyun.com/ubuntu/ xenial main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ xenial-security main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ xenial-updates main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ xenial-backports main restricted universe multiverse
##测试版源
deb http://mirrors.aliyun.com/ubuntu/ xenial-proposed main restricted universe multiverse
# 源码
deb-src http://mirrors.aliyun.com/ubuntu/ xenial main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ xenial-security main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ xenial-updates main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ xenial-backports main restricted universe multiverse
##测试版源
deb-src http://mirrors.aliyun.com/ubuntu/ xenial-proposed main restricted universe multiverse
# Canonical 合作伙伴和附加
deb http://archive.canonical.com/ubuntu/ xenial partner
deb http://extras.ubuntu.com/ubuntu/ xenial main
```
## 安装Apache
```shell
sudo apt-get update
sudo apt-get install tasksel
sudo tasksel
需要设置账号root和密码123456
```
## 安装workbench
```shell
sudo apt-get install mysql-workbench
```
## MySQL命令行操作
### 连接到本机上的MYSQL
```shell
mysql -u root -p
然后提示输入密码：123456
接下来进入mysql中，提示符为mysql>
```
### 退出MYSQL命令： exit （回车）
### 创建数据库
```shell
create database <数据库名>;
```
### 显示数据库
```shell
show databases;
```
### 删除数据库
```shell
drop database <数据库名>;
```
### 使用数据库
```shell
use <数据库名>;
```
### 创建数据表
```shell
create table <表名> ( <字段名1> <类型1> [,..<字段名n> <类型n>]);
```
### 查看表结构
```shell
desc 表名;
```
### 删除表
```shell
drop table <表名>;
```
### 插入数据
```shell
insert into <表名> [( <字段名1>[,..<字段名n > ])] values ( 值1 )[, ( 值n )];
```
### 查询数据
```shell
select 查询信息 from 表名 where 表达式
```
### 删除数据
```shell
delete from 表名 where 表达式
```
### 修改数据
```shell
update 表名 set <列名>=<表达式> [,<列名>=<表达式>]... where 条件;
```
### 增加字段
```shell
alter table 表名 add 字段 类型 其他;
```
### 添加索引
```shell
* 加索引 mysql> alter table 表名 add index 索引名 (字段名1[，字段名2 ...]);
* 加主关键字的索引 mysql> alter table 表名 add primary key (字段名);
* 加唯一限制条件的索引 mysql> alter table 表名 add unique 索引名 (字段名);
```
### 查看索引
```shell
show index from 表名
```
### 删除索引
```shell
alter table 表名 drop index 索引名;
```
### 修改字段
```shell
ALTER TABLE table_name ADD field_name field_type;
```
### 修改原字段名称及类型
```shell
ALTER TABLE table_name CHANGE old_field_name new_field_name field_type;
```
### 删除字段
```shell
MySQL ALTER TABLE table_name DROP field_name;
```
### 修改表名
```shell
rename table 原表名 to 新表名;
当你执行 RENAME 时，你不能有任何锁定的表或活动的事务。你同样也必须有对原初表的 ALTER 和 DROP 权限，以及对新表的 CREATE 和 INSERT 权限
```
## MYSQL数据库备份、导入
### 数据库备份
```shell
1.导出整个数据库 导出文件默认是存在mysql\bin目录下 mysqldump -u 用户名 -p 数据库名 > 导出的文件名 
例如：mysqldump -u user_name -p123456 database_name > outfile_name.sql

2.导出一个表 mysqldump -u 用户名 -p 数据库名 表名> 导出的文件名 
例如：mysqldump -u user_name -p database_name table_name > outfile_name.sql

3.导出一个数据库结构 mysqldump -u user_name -p -d –add-drop-table database_name > outfile_name.sql -d 
没有数据 –add-drop-table 在每个create语句之前增加一个drop table

4.带语言参数导出 mysqldump -uroot -p –default-character-set=latin1 –set-charset=gbk –skip-opt database_name > outfile_name.sql

例如，将aaa库备份到文件back_aaa中： [root@test1 root]# cd /home/data/mysql [root@test1 mysql]# mysqldump -u root -p --opt aaa > back_aaa

.远程数据库（表）导出到本地数据库（表）文件 
* ##### （1）导出数据库 
* mysqldump -h192.168.1.1 -uroot -p123456 --databases mydb > mydb.bak;//将192.168.1.1主机上的mydb数据库导出到本地的mydb.bak文件中 
* （mysqldump -uroot -p123456 --databases mydb1 > mydb1.bak;//将本地mysql服务器上的mydb1数据库导出到本地的mydb1.bak文件中） 
* ##### （2）导出数据表 
* mysqldump -h192.168.1.1 -uroot -p123456 mydb tb1 > tb1.bak;//将192.168.1.1主机上的mydb数据库的tb1数据表导出到本地的tb1.bak文件中 
* （mysqldump -uroot -p123456 mydb1 tb2 > tb2.bak;//将本地主机上的mydb1数据库的tb2数据表导出到本地的tb2.bak文件中）

5. 导出表数据到文件中： mysql -uroot -p123456 --default-character-set=utf8 use guanjia; select _from driver into outfile '/tmp/a.txt'; 
(select_ from crawlDocs order by DocCrawlTime desc limit 2000 into outfile '/tmp/weixinData' FIELDS TERMINATED BY ',';) 
一般最好是导出到/tmp目录下，因为这样mysql用户也可以写入。
```
### 数据库导入
```shell
1. 导入数据库
在本地数据库中创建相对应导出的数据库mydb同名的数据库： mysql> create database mydb; 
然后退出数据库，再使用以下的 命令导入数据库文件mydb.bak到本地数据库mydb中： mysql -uroot -p123456 mydb < /root/data/mydb.bak;

2. 导入数据表
然后在mysql中使用source指令来完成数据表的导入，如下： mysql> source /root/data/tb1.bak; 
/root/data/tb1.bak是远程数据表tb1导出文件的本地存放位置

3. 表数据导入到数据表中
 mysql -uroot -p123456 --default-character-set=utf8 use guanjia; load data infile '/tmp/a.txt' into table test CHARACTER SET utf8;
(load data infile '/tmp/weiData' into table crawlDocs CHARACTER SET utf8 FIELDS TERMINATED BY ',';)
如果导入时出现类似 ERROR 29 (HY000): File '/tmp/a.txt' not found (Errcode: 13)的错误，则很可能是因为mysql用户没有权限访问该文件，
则使用 chown mysql:mysql /tmp/a.txt 将该文件的所属设为mysql用户，再次执行上面的命令则一般可以完成导入。
```

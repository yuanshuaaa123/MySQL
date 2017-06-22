#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "cgic.h"
char * headname = "head.html";
char * footname = "foot.html";

int cgiMain()
{

	fprintf(cgiOut, "Content-type:text/html;charset=utf-8\n\n");

	char sname[32] = "\0";
	char sage[16] = "\0";
	char sno[32] = "\0";
	char ssex[16] = "\0";
	char mno[16] = "\0";
	//char state[4] = "\0";
	int status = 0;

	status = cgiFormString("sname",  sname, 32);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get sname error!\n");
		return 1;
	}

	status = cgiFormString("sage",  sage, 16);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get sage error!\n");
		return 1;
	}

	status = cgiFormString("sno",  sno, 32);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get sno error!\n");
		return 1;
	}

	status = cgiFormString("ssex",  ssex, 32);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get ssex error!\n");
		return 1;
	}

	status = cgiFormString("mno",  mno, 32);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get mno error!\n");
		return 1;
	}

	FILE * fd;
	char ch;
	if(!(fd = fopen(headname, "r"))){
		fprintf(cgiOut, "Can not open file, %s\n", headname);
		return -1;
	}

	ch = fgetc(fd);
	while(ch != EOF){
		fprintf(cgiOut, "%c", ch);
		ch = fgetc(fd);
	}
	fclose(fd);
	//status = cgiFormString("state",  state, 4);
	//if (status != cgiFormSuccess)
	//{
	//	fprintf(cgiOut, "get state error!\n");
	//	return 1;
	//}

	//fprintf(cgiOut, "name = %s, age = %s, stuId = %s\n", name, age, stuId);

	int ret;
	char sql[128] = "\0";
	MYSQL *db;

	//初始化
	db = mysql_init(NULL);
	if (db == NULL)
	{
		fprintf(cgiOut,"mysql_init fail:%s\n", mysql_error(db));
		return -1;
	}

	//连接数据库
	db = mysql_real_connect(db, "127.0.0.1", "root", "123456", "stu",  3306, NULL, 0);
	if (db == NULL)
	{
		fprintf(cgiOut,"mysql_real_connect fail:%s\n", mysql_error(db));
		mysql_close(db);
		return -1;
	}



	strcpy(sql, "create table info(sno int(4) primary key, sname varchar(10) not null, sage smallint not null, ssex char(4) not null, mno int(4) not null, foreign key(mno) references school(mno), state int(4) default '1' )");
	if ((ret = mysql_real_query(db, sql, strlen(sql) + 1)) != 0)
	{
		if (ret != 1)
		{
			fprintf(cgiOut,"mysql_real_query fail:%s\n", mysql_error(db));
			mysql_close(db);
			return -1;
		}
	}


	sprintf(sql, "insert into info values(%d, '%s', %d, '%s', %d, '1')", atoi(sno), sname, atoi(sage), ssex, atoi(mno));
	if (mysql_real_query(db, sql, strlen(sql) + 1) != 0)
	{
		fprintf(cgiOut, "%s\n", mysql_error(db));
		mysql_close(db);
		return -1;
	}

	fprintf(cgiOut, "add student ok!\n");
	mysql_close(db);
	return 0;
}

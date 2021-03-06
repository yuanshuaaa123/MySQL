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

	char sno[32] = "\0";
	char flag[4] = "\0";
	int status = 0;


	status = cgiFormString("sno",  sno, 32);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get sno error!\n");
		return 1;
	}

	status = cgiFormString("flag",  flag, 4);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get flag error!\n");
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

	if(flag[0] == '1'){
		sprintf(sql, "delete from info where sno = %d", atoi(sno));
		if ((ret = mysql_real_query(db, sql, strlen(sql) + 1)) != 0)
		{
			fprintf(cgiOut,"mysql_real_query fail:%s\n", mysql_error(db));
			mysql_close(db);
			return -1;
		}
	}else{
		sprintf(sql, "update info set state = '0' where sno = %d", atoi(sno));
		if ((ret = mysql_real_query(db, sql, strlen(sql) + 1)) != 0)
		{
			fprintf(cgiOut,"mysql_real_query fail:%s\n", mysql_error(db));
			mysql_close(db);
			return -1;
		}
	}




	fprintf(cgiOut, "delete student ok!\n");
	mysql_close(db);

	return 0;
}

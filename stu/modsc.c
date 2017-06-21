#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "cgic.h"

int cgiMain()
{

	fprintf(cgiOut, "Content-type:text/html;charset=utf-8\n\n");

  char mname[32] = "\0";
  char mdept[32] = "\0";
	char mno[32] = "\0";
	int status = 0;

  status = cgiFormString("mname",  mname, 32);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get mname error!\n");
		return 1;
	}

  status = cgiFormString("mdept",  mdept, 32);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get mdept error!\n");
		return 1;
	}

	status = cgiFormString("mno",  mno, 32);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get mno error!\n");
		return 1;
	}

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


	fprintf(cgiOut,"update school set mname='%s', mdept= '%s' where mno = %d ", mname, mdept, atoi(mno));
	fprintf(cgiOut, "<hr>");
	sprintf(sql, "update school set mname='%s', mdept= '%s' where mno = %d ", mname, mdept, atoi(mno));
	if ((ret = mysql_real_query(db, sql, strlen(sql) + 1)) != 0)
	{
		fprintf(cgiOut,"mysql_real_query fail:%s\n", mysql_error(db));
		mysql_close(db);
		return -1;
	}



	fprintf(cgiOut, "update school ok!\n");
	mysql_close(db);
	return 0;
}

# 技术文档

[Linux](./Linux.md)

[Git](./Git.md)

[Database](./Database.md)

# 课程设计


## 学生信息表设计
| 中文名称 | 表名 | 字段属性 | 备注 |
|---------|-----|---------|------|
| 学号 | sno | int(4) | 主码 |
| 姓名 | sname | varchar(10) | 不能为空 |
| 年龄 | sage | int(4) | 不能为空 |
| 性别 | ssex | char(4) | 男/女 |
| 专业号 | mno | int(4)| 外码 不能为空 |


## 学院信息表设计
| 中文名称 | 表名 | 字段属性 | 备注 |
|---------|-----|---------|------|
| 专业号 | mno | int(4) | 主码 |
| 专业名 | mname | char(10) | 不能为空 |
| 学院名 | mdept | char(10) | 不能为空 |


## 学生成绩表设计
| 中文名称 | 表名 | 字段属性 | 备注 |
|---------|-----|---------|------|
| 学号 | sno | int(4) | 主码 |
| 课程名 | cname | char(10) | 主码 |
| 成绩 | score | int(4) | 0-100 |


# 每天计划

[20170612](./20170612.md)

[20170613](./20170613.md)

[20170614](./20170614.md)

[20170615](./20170615.md)

[20170616](./20170616.md)

[20170619](./20170619.md)

[20170620](./20170620.md)
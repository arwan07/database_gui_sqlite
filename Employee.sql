CREATE TABLE "EMPLOYEES" (
	"EMPLOYEE_ID"	NUMERIC(6) NOT NULL,
	"FIRST_NAME"	VARCHAR(20),
	"LAST_NAME"	VARCHAR(25),
	"EMAIL"	VARCHAR(25),
	"PHONE_NUMBER"	VARCHAR(20),
	"HIRE_DATE"	DATE,
	"JOB_ID"	VARCHAR(10),
	"SALARY"	NUMERIC(8, 2),
	"COMMISSION_PCT"	NUMERIC(2, 2),
	"MANAGER_ID"	NUMERIC(6),
	"DEPARTMENT_ID"	NUMERIC(4),
	"BONUS"	VARCHAR(5)
);
INSERT INTO employees(employee_id,first_name,last_name,email,phone_number,hire_date,job_id,salary,commission_pct,manager_id,department_id)
VALUES(100,'Steven','King','SKING','515.123.4567','1987-06-17','AD_PRES',24000,null,null,90);
INSERT INTO employees(employee_id,first_name,last_name,email,phone_number,hire_date,job_id,salary,commission_pct,manager_id,department_id)
VALUES(101,'Neena','Kochhar','NKOCHHAR','515.123.4568','1989-09-21','AD_VP',17000,null,100,90 );
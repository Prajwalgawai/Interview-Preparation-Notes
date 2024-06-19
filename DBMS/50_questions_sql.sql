-- worker.* means all columns from worker table.

-- Q-1. Write an SQL query to fetch “FIRST_NAME” from Worker table using the alias name as <WORKER_NAME>.
select FIRST_NAME AS worker_name from worker;

-- Q-2. Write an SQL query to fetch “FIRST_NAME” from Worker table in upper case.
select UPPER(FIRST_NAME) FROM worker; 

-- Q-3. Write an SQL query to fetch unique values of DEPARTMENT from Worker table.
SELECT distinct DEPARTMENT FROM DEPARTMENT;  //HW GROUP BY

-- Q-4. Write an SQL query to print the first three characters of  FIRST_NAME from Worker table.
SELECT substring(FIRST_NAME, 1, 3) FROM Worker;

-- Q-5. Write an SQL query to find the position of the alphabet (‘b’) in the first name column ‘Amitabh’ from Worker table.
select INSTR(first_name, 'b') from worker where first_name="Amitabh";

-- Q-6. Write an SQL query to print the FIRST_NAME from Worker table after removing white spaces from the right side.
select RTRIM(first_name) from worker;

-- Q-7. Write an SQL query to print the DEPARTMENT from Worker table after removing white spaces from the left side.
select LTRIM(first_name) from worker;

-- Q-8. Write an SQL query that fetches the unique values of DEPARTMENT from Worker table and prints its length.
select distinct department, LENGTH(department) from worker;

-- Q-9. Write an SQL query to print the FIRST_NAME from Worker table after replacing ‘a’ with ‘A’.
select REPLACE(first_name, 'a', 'A') from worker;

-- Q-10. Write an SQL query to print the FIRST_NAME and LAST_NAME from Worker table into a single column COMPLETE_NAME.
-- A space char should separate them.
select CONCAT(first_name,' ', LAST_NAME) as COMPLETE_NAME from worker;       //vimp

-- Q-11. Write an SQL query to print all Worker details from the Worker table order by FIRST_NAME Ascending.
select * from worker ORDER by first_name ASC;              //important.

-- Q-12. Write an SQL query to print all Worker details from the Worker table order by 
-- FIRST_NAME Ascending and DEPARTMENT Descending.
select * from worker ORDER by first , department DESC;

-- Q-13. Write an SQL query to print details for Workers with the first name as “Vipul” and “Satish” from Worker table.
select * from worker where first_name IN("vipul", "satish");

-- Q-14. Write an SQL query to print details of workers excluding first names, “Vipul” and “Satish” from Worker table.
select * from worker where first_name NOT IN("vipul", "satish");

-- Q-15. Write an SQL query to print details of Workers with DEPARTMENT name as “Admin*”.
select * from worker where first_name LIKE "Admin%";

-- Q-16. Write an SQL query to print details of the Workers whose FIRST_NAME contains ‘a’.
select * from worker where first_name LIKE"%a%";


-- Q-17. Write an SQL query to print details of the Workers whose FIRST_NAME ends with ‘a’.
select * from worker where first_name LIKE "%a";

-- Q-18. Write an SQL query to print details of the Workers whose FIRST_NAME ends with ‘h’ and contains six alphabets.
select * from worker where first_name LIKE "_____h";

-- Q-19. Write an SQL query to print details of the Workers whose SALARY lies between 100000 and 500000.
select * from worker where SALARY between 100000 and 500000;

-- Q-20. Write an SQL query to print details of the Workers who have joined in Feb’2014.
select * from worker where JOINING_DATE="Feb 2024";      //this is wrong.
select * from worker where YEAR(JOINGING_DATE)=2024 AND MONTH(JOINGING_DATE)=02;                  //very important(right).

-- Q-21. Write an SQL query to fetch the count of employees working in the department ‘Admin’.
select COUNT(employees) from worker where department="Admin";
-- or
select department, COUNT(*) from worker where department="Admin";

-- Q-22. Write an SQL query to fetch worker full names with salaries >= 50000 and <= 100000.
select CONCAT(first_name, ' ', LAST_NAME) from worker where salary between 50000 and 100000;               //important.


-- Q-23. Write an SQL query to fetch the no. of workers for each department in the descending order.
select COUNT(worker_id), department from worker GROUP By department ORDER BY COUNT(worker_id); //in output of this, first count and then corresponding department name side by side will be printed.
select department, COUNT(worker_id) from worker GROUP BY department ORDER BY COUNT(worker_id); //here first department name then corresponding count side by side will be printed

-- Q-24. Write an SQL query to print details of the Workers who are also Managers.  📌📌
select w.* from worker as w inner join title as t on w.worker_id=t.worker_ref_id where worker_title="Manager";    //due to w.* details of worker table will be printed only.

-- Q-25. Write an SQL query to fetch number (more than 1) of same titles in the ORG of different types.
select worker_title , COUNT(*) as count from title group by worker_title having count>1;          //important       //does not understood.

-- Q-26. Write an SQL query to show only odd rows from a table.
-- select * from worker where MOD(worker_id, 2)!=0;                                               -- 📌important.
or
select * from worker where MOD(worker_id, 2)<>0;


-- Q-27. Write an SQL query to show only even rows from a table.
select * from worker where MOD(worker_id, 2)=0;                           -- 🌟

-- Q-28. Write an SQL query to clone a new table from another table.
create Table clone_table LIKE worker     --      📌very important        //creates same table schema for clone_table like worker but dont fill entries automatically.

insert INTO clone_table select * from worker;      --📌 //this inserting entries.

-- Q-29. Write an SQL query to fetch intersecting records of two tables.
select worker.* from worker inner join clone_table using (worker_id);      --📌"using" is same as on worker.worker_id=clone_table.worker_id;

-- Q-30. Write an SQL query to show records from one table that another table does not have.
-- MINUS
select worker.* from worker left join clone_table using (worker_id) where clone_table.worker_id=NULL;  --📌means all entries of left table which does not matches with right table.

-- Q-31. Write an SQL query to show the current date and time.       📌
-- DUAL
select curdate();           //important
select now();

-- Q-32. Write an SQL query to show the top n (say 5) records of a table order by descending salary.
select * from worker order by salary desc limit 5;       //this will perform query on only top 5 elements now.

-- Q-33. Write an SQL query to determine the nth (say n=5) highest salary from a table.
select * from worker order by salary desc limit 4, 1;       -- 📌means 1st entry after 4th entry.(limit 4, 2 means 2nd entry after 4th one).  

-- Q-34. Write an SQL query to determine the 5th highest salary without using LIMIT keyword.
SELECT DISTINCT salary FROM employees e1 WHERE 5 = (SELECT COUNT(DISTINCT salary) FROM employees e2 WHERE e2.salary > e1.salary ); -- easy just think.

-- Q-35. Write an SQL query to fetch the list of employees with the same salary.
select w1.* from worker w1, worker w2 where w1.salary = w2.salary and w1.worker_id != w2.worker_id; -- 📌when we use , bet'n two tables it is cross join.

-- Q-36. Write an SQL query to show the second highest salary from a table using sub-query.
select max(salary) from worker                                      -- 📌
where salary not in (select max(salary) from worker);

-- Q-37. Write an SQL query to show one row twice in results from a table.           📌
select * from worker
UNION ALL
select * from worker ORDER BY worker_id;

--Q.38 Write an SQL query to show all except top 5 workers having highest salaries.
select * from worker order by salary ASC offset 5 ROWS                      --📌 this will return skip last 5 records from o/p table.
                                         --offset is used to skip the rows from the end of resultant table
            --using subquery : 
SELECT DISTINCT salary FROM employees e1 WHERE 5 < (SELECT COUNT(DISTINCT salary) FROM employees e2 WHERE e2.salary > e1.salary);   --important
                             

-- Q-38. Write an SQL query to list worker_id who does not get bonus.
select worker_id from worker where worker_id not in (select worker_ref_id from bonus);                --important

-- Q-39. Write an SQL query to fetch the first 50% records from a table.
select * from worker where worker_id <= ( select count(worker_id)/2 from worker);

-- Q-40. Write an SQL query to fetch the departments that have less than 4 people in it.
select department, count(department) as depCount from worker group by department having depCount < 4;   --📌

-- Q-41. Write an SQL query to show all departments along with the number of people in there.
select department, count(department) as depCount from worker group by department;

-- Q-42. Write an SQL query to show the last record from a table.
select * from worker where worker_id = (select max(worker_id) from worker);

-- Q-43. Write an SQL query to fetch the first row of a table.
select * from worker where worker_id = (select min(worker_id) from worker);

-- Q-44. Write an SQL query to fetch the last five records from a table.
(select * from worker order by worker_id desc limit 5) order by worker_id;           --     📌

-- Q-45. Write an SQL query to print the name of employees having the highest salary in each department.
select w.department, w.first_name, w.salary from
 (select max(salary) as maxsal, department from worker group by department) temp
inner join worker w on temp.department = w.department and temp.maxsal = w.salary;

-- Q-46. Write an SQL query to fetch three max salaries from a table using co-related subquery
select distinct salary from worker w1
where 3 >= (select count(distinct salary) from worker w2 where w1.salary <= w2.salary) order by w1.salary desc;
-- DRY RUN AFTER REVISING THE CORELATED SUBQUERY CONCEPT FROM LEC-9.
select distinct salary from worker order by salary desc limit 3;

-- Q-47. Write an SQL query to fetch three min salaries from a table using co-related subquery
select distinct salary from worker w1
where 3 >= (select count(distinct salary) from worker w2 where w1.salary >= w2.salary) order by w1.salary desc;

-- Q-48. Write an SQL query to fetch nth max salaries from a table.
select distinct salary from worker w1
where n >= (select count(distinct salary) from worker w2 where w1.salary <= w2.salary) order by w1.salary desc;

-- Q-49. Write an SQL query to fetch departments along with the total salaries paid for each of them.
select department , sum(salary) as depSal from worker group by department order by depSal desc;

-- Q-50. Write an SQL query to fetch the names of workers who earn the highest salary.
select first_name, salary from worker where salary = (select max(Salary) from worker);

--Q-51. Department Highest Salary for Each Department.
select dp.name as Department, em.name as Employee, em.salary as Salary from Employee as em inner join Department
 as dp on em.departmentId=dp.id where (em.departmentId, em.salary) IN (select departmentId, Max(salary) from 
 Employee group by departmentId);
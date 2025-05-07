# Write your MySQL query statement below
select unique_id,name from EmployeeUNI as a right join Employees as b on a.id=b.id;
# Write your MySQL query statement below
select en.unique_id, em.name 
from Employees em
left outer join EmployeeUNI en
on em.id=en.id
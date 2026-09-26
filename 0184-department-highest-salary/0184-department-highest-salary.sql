select d1.name AS Department, e1.name AS Employee, e1.salary
from Employee e1
left join Department d1
ON e1.departmentId = d1.id
where (salary,departmentId) IN (
    select MAX(e2.salary) , e2.departmentId
    from Employee e2
    group by e2.departmentId
);
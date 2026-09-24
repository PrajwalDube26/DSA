select e1.employee_id
from Employees e1
where (e1.manager_id) NOT IN (
    select e2.employee_id
    from Employees e2
) AND e1.salary<30000
order by e1.employee_id;
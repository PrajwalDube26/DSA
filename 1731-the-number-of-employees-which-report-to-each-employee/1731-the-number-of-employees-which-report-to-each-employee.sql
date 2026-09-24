select e1.reports_to AS employee_id,(
    select e2.name
    from Employees e2
    where e1.reports_to = e2.employee_id
) AS name, COUNT(*) AS reports_count, ROUND(AVG(age),0) AS average_age
from Employees e1
group by e1.reports_to
having e1.reports_to IS NOT NULL
order by e1.reports_to;
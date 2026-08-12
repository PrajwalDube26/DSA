select Eo.name AS Employee
FROM Employee Eo
WHERE Eo.salary > (select e.salary
                FROM Employee e
                WHERE Eo.managerId=e.id
                );
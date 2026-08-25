select employee_id , CASE
                        when employee_id % 2 =1 AND name NOT LIKE "M%" then salary
                        else 0
                    END AS bonus
FROM Employees
ORDER BY employee_id;
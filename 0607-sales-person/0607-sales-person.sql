select s2.name
from SalesPerson s2
where (s2.sales_id) NOT IN (
                            select o1.sales_id
                            from Orders o1
                            left join Company c1
                            on o1.com_id = c1.com_id
                            where c1.name = "RED"
                           );
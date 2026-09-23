select p.product_name , SUM(o.unit) AS unit
from Orders o
left join Products p
ON o.product_id = p.product_id
where order_date between '2020-02-01' AND '2020-02-29'
group by o.product_id
having SUM(o.unit)>99;
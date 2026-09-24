select p.product_id ,
CASE
    WHEN ROUND(SUM(u.units * p.price)/SUM(u.units) ,2) is null THEN 0
    WHEN ROUND(SUM(u.units * p.price)/SUM(u.units) ,2) THEN ROUND(SUM(u.units * p.price)/SUM(u.units) ,2)
END AS average_price
from UnitsSold u
right join Prices p
on u.product_id = p.product_id AND u.purchase_date between p.start_date and p.end_date 
group by p.product_id;
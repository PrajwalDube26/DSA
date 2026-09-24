select s1.product_id, s1.year AS first_year, s1.quantity, s1.price
from Sales s1
where (s1.product_id,s1.year) IN (
    select s2.product_id,MIN(s2.year)
    from Sales s2
    group by s2.product_id
);
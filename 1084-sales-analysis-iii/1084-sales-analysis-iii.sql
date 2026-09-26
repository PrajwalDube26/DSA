select P2.product_id, P2.product_name
from Product p2
where (p2.product_id) NOT IN (
    select p1.product_id
    from Sales s1
    right join Product p1
    on s1.product_id = p1.product_id
    where s1.sale_date NOT BETWEEN '2019-01-01' AND '2019-03-31' OR s1.seller_id IS NULL
)
ORDER BY P2.product_id;
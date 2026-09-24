select customer_id
from Customer
group by customer_id
having (COUNT(DISTINCT customer_id,product_key )) IN (
    select COUNT(product_key)
    from Product
);
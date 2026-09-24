select q1.query_name,ROUND(AVG(q1.rating/q1.position) ,2) AS quality , 
(
 select ROUND(100*count(q2.query_name)/count(q1.query_name),2)
 from Queries q2
 where q2.rating<3 AND q1.query_name = q2.query_name
)AS poor_query_percentage
from Queries q1
group by q1.query_name;
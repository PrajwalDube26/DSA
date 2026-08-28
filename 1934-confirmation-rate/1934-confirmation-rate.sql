select s.user_id ,
ROUND(AVG(
    CASE 
        WHEN c.action="timeout" THEN 0
        WHEN c.action="confirmed" THEN 1
        WHEN c.action IS NULL THEN 0
    END
),2) AS confirmation_rate
from Confirmations c
RIGHT JOIN Signups s
ON c.user_id = s.user_id
GROUP BY s.user_id;
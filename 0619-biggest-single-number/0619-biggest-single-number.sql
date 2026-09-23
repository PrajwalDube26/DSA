select MAX(t.num) AS num
from (select num
from MyNumbers
group by num
HAVING COUNT(*)=1) t;
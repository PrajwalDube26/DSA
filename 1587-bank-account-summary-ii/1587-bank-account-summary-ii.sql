select u.name, SUM(t.amount) AS balance
from Transactions t
left join Users u
ON t.account = u.account
group by t.account
having SUM(t.amount) > 10000;
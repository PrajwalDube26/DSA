SELECT p1.email AS Email
FROM Person p1
GROUP BY p1.email
HAVING COUNT(p1.email)>1;
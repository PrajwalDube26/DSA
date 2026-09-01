-- SELECT v.customer_id , CASE
--                         WHEN COUNT(v.customer_id) IS NOT NULL THEN COUNT(v.customer_id)
--                        END AS count_no_trans
-- FROM Visits v
-- LEFT JOIN Transactions t
-- ON v.visit_id=t.visit_id
-- WHERE t.transaction_id IS NULL
-- GROUP BY v.customer_id;

SELECT v.customer_id ,  COUNT(v.customer_id) AS count_no_trans
FROM Visits v
LEFT JOIN Transactions t
ON v.visit_id=t.visit_id
WHERE t.transaction_id IS NULL
GROUP BY v.customer_id
HAVING COUNT(v.customer_id) IS NOT NULL;
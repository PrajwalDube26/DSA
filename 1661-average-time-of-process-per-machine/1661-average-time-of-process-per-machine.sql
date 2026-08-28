-- select a1.machine_id ,ROUND(AVG(CASE
--                                     WHEN a1.activity_type="start"
--                                     THEN (select a2.timestamp - a1.timestamp
--                                             FROM Activity a2
--                                             WHERE a2.activity_type="end" AND a2.machine_id=a1.machine_id AND a2.process_id=a1.process_id)
--                                     END),3) AS processing_time
-- FROM Activity a1
-- WHERE a1.activity_type = "start"
-- GROUP BY machine_id;




select a1.machine_id ,ROUND(AVG(a2.timestamp - a1.timestamp),3) AS processing_time
FROM Activity a1
JOIN Activity a2
ON a1.machine_id = a2.machine_id && a1.process_id = a2.process_id && a2.activity_type="end"
WHERE a1.activity_type = "start"
GROUP BY machine_id;
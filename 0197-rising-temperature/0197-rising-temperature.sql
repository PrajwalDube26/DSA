-- select w1.id AS id
-- from Weather w1
-- where w1.temperature > (
--     select w2.temperature
--     from Weather w2
--     where w2.recordDate = DATE_SUB(w1.recordDate , INTERVAL 1 DAY)
-- );

select w1.id AS id
from Weather w1
JOIN Weather w2
ON w1.recordDate = DATE_add(w2.recordDate, INTERVAL 1 DAY)
WHERE w2.temperature < w1.temperature;
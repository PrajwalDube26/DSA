select event_day As day , emp_id, SUM(out_time-in_time) AS total_time
from Employees
group by emp_id,event_day
order by event_day,emp_id;
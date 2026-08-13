select name
from Customer
where referee_id IS NULL || referee_id != 2;
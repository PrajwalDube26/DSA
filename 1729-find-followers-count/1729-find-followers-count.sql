select user_id, COUNT(DISTINCT(follower_id )) AS followers_count
from Followers
group by user_id;
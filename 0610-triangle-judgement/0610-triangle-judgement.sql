select * ,CASE
            WHEN x>=y AND x>=z AND x>=y+z THEN "No"
            WHEN x>=y AND x>=z AND x<y+z THEN "Yes"

            WHEN y>=x AND y>=z AND y>=x+z THEN "No"
            WHEN y>=x AND y>=z AND y<x+z THEN "Yes"

            WHEN z>=y AND z>=x AND z>=y+x THEN "No"
            WHEN z>=y AND z>=x AND z<y+x THEN "Yes"
          END AS triangle
from Triangle;
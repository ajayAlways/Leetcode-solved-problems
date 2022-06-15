# Write your MySQL query statement below

SELECT t1.actor_id, t1.director_id FROM (SELECT actor_id, director_id,COUNT(*) as num_count
FROM ActorDirector
GROUP BY actor_id, director_id) t1
WHERE t1.num_count>=3
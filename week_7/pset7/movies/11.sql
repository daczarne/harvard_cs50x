SELECT
    title
FROM ratings AS r
LEFT JOIN movies AS m
    ON r.movie_id = m.id
WHERE movie_id IN (SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = "Chadwick Boseman"))
ORDER BY rating DESC
LIMIT 5;
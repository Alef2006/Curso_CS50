SELECT m.title FROM movies m
JOIN stars s ON s.movie_id=m.id
JOIN people p ON s.person_id=p.id
JOIN ratings r ON s.movie_id=r.movie_id
WHERE p.name="Chadwick Boseman"
ORDER BY r.rating ASC LIMIT 5;
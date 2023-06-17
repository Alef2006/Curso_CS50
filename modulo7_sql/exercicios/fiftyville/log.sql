-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Lendo o relatorio do crime

--SELECT description,year FROM crime_scene_report WHERE day=28  AND month =7 AND street="Chamberlin Street";

-- Relatorio das testemunhas

SELECT name,transcript FROM interviews WHERE transcript LIKE "%courthouse%" AND day=28  AND month =7 AND year=2020;

-- Descobrindo para onde o ladrao fugiu

/*
SELECT a.city FROM airports a WHERE a.id IN (
    SELECT f.destination_airport_id FROM flights f
    JOIN airports a ON f.origin_airport_id=a.id
    WHERE a.city="Fiftyville" AND f.day=29 AND f.month=7 AND f.year=2020 ORDER BY f.hour  LIMIT 1
);
*/

-- Descobrindo quem e o ladrao

-- SELECT *FROM  courthouse_security_logs WHERE day=28 AND month=7 AND year=2020 AND hour=10 AND minute>15 AND minute<=25;

/*
SELECT p.name,p.license_plate FROM people p
WHERE license_plate IN(
SELECT license_plate FROM  courthouse_security_logs
WHERE day=28
AND month=7
AND year=2020
AND hour=10
AND minute>15 AND minute<=25
);
*/

/*
SELECT p.name,p.phone_number FROM people p
JOIN passengers pf ON pf.passport_number=p.passport_number
WHERE pf.flight_id=36;
*/

--Suspeitos Ernest ,Roger,Evelyn
--Todos sairam da garagem no intervalo de 10 minutos apos o roubo e estão no primeiro voo do dia posterior


SELECT caller,receiver FROM phone_calls
WHERE day=28
AND month=7
AND year=2020
AND duration<60;

--Suspeitos Ernest ,Roger,Evelyn
-- Todos ligaram para alguem no dia do roubo e suas ligacoes duraram menos de 60 minutos


 SELECT *FROM atm_transactions  WHERE  day=28
AND month=7
AND year=2020
AND transaction_type="withdraw"
AND atm_location ="Fifer Street"
;

/*
SELECT p.name FROM people p
JOIN bank_accounts ba ON ba.person_id=p.id
JOIN atm_transactions at ON at.account_number=ba.account_number
WHERE at.day=28
AND at.month=7
AND at.year=2020
AND at.transaction_type="withdraw"
AND at.atm_location ="Fifer Street";
*/

-- Ernest foi o unico dos três suspeitos que realizou um saque na fifer street
-- O ladrão e Ernest

-- Descobrindo quem e o cumplice de Ernest

SELECT p.name,p.phone_number FROM people p
WHERE p.phone_number IN(
      SELECT pc.receiver FROM phone_calls pc
      WHERE pc.caller IN (
         SELECT p.phone_number FROM people p
         WHERE p.name="Ernest"
      ) AND pc.day=28 AND pc.month=7 AND pc.year=2020 AND duration <60
);

SELECT p.name,p.phone_number FROM people p
WHERE p.name="Ernest";

SELECT caller,receiver FROM phone_calls
WHERE day=28
AND month=7
AND year=2020
AND duration<60;



-- Id do primeiro Voo do dia posterior a o roubo=36

 /*
  SELECT f.id FROM flights f
  JOIN airports a ON f.origin_airport_id=a.id
  WHERE a.city="Fiftyville" AND f.day=29 AND f.month=7 AND f.year=2020 ORDER BY f.hour  LIMIT 1;
*/




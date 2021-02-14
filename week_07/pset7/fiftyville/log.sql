-- Get the report
SELECT *
FROM crime_scene_reports
WHERE day = 28
    AND month = 7
    AND year = 2020
    AND street LIKE "Chamberlin%";
-- id  | year | month | day | street            | description
-- 295 | 2020 | 7     | 28  | Chamberlin Street | Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. Interviews
--                                                were conducted today with three witnesses who were present at the time — each of their interview
--                                                transcripts mentions the courthouse.

-- Review the interviews
select *
from interviews
where year = 2020
    and month = 7
    and day = 28;
-- id  | name    | year | month | day | transcript
-- 161 | Ruth    | 2020 | 7     | 28  | Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive a
--                                      way. If you have security footage from the courthouse parking lot, you might want to look for cars that left the
--                                      parking lot in that time frame.
-- 162 | Eugene  | 2020 | 7     | 28  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the
--                                      courthouse, I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.
-- 163 | Raymond | 2020 | 7     | 28  | As the thief was leaving the courthouse, they called someone who talked to them for less than a minute. In the
--                                      call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The
--                                      thief then asked the person on the other end of the phone to purchase the flight ticket.


-- Check ATM transactions
select account_number
from atm_transactions
where year = 2020
    and month = 7
    and day = 28
    and atm_location = "Fifer Street"
    and transaction_type = "withdraw";
-- id  | account_number | year | month  | day | atm_location | transaction_type | amount
-- 246 | 28500762       | 2020 | 7      | 28  | Fifer Street | withdraw         | 48
-- 264 | 28296815       | 2020 | 7      | 28  | Fifer Street | withdraw         | 20
-- 266 | 76054385       | 2020 | 7      | 28  | Fifer Street | withdraw         | 60
-- 267 | 49610011       | 2020 | 7      | 28  | Fifer Street | withdraw         | 50
-- 269 | 16153065       | 2020 | 7      | 28  | Fifer Street | withdraw         | 80
-- 288 | 25506511       | 2020 | 7      | 28  | Fifer Street | withdraw         | 20
-- 313 | 81061156       | 2020 | 7      | 28  | Fifer Street | withdraw         | 30
-- 336 | 26013199       | 2020 | 7      | 28  | Fifer Street | withdraw         | 35

-- Get the list of people who where at the bank
select *
from people
where id IN (
    select person_id
    from bank_accounts
    where account_number IN (
        select account_number
        from atm_transactions
        where year = 2020
            and month = 7
            and day = 28
            and atm_location = "Fifer Street"
            and transaction_type = "withdraw"
    )
);
-- id     | name      | phone_number   | passport_number | license_plate
-- 395717 | Bobby     | (826) 555-1652 | 9878712108      | 30G67EN
-- 396669 | Elizabeth | (829) 555-5269 | 7049073643      | L93JTIZ
-- 438727 | Victoria  | (338) 555-6650 | 9586786673      | 8X428L0
-- 449774 | Madison   | (286) 555-6063 | 1988161715      | 1106N58
-- 458378 | Roy       | (122) 555-4581 | 4408372428      | QX4YZN3
-- 467400 | Danielle  | (389) 555-5198 | 8496433585      | 4328GD8
-- 514354 | Russell   | (770) 555-1861 | 3592750733      | 322W7JE
-- 686048 | Ernest    | (367) 555-5533 | 5773159633      | 94KL13X


-- Get list of people who left courthouse
select *
from people
where license_plate IN (
    select license_plate
    from courthouse_security_logs
    where year = 2020
        and month = 7
        and day = 28
        and hour = 10
        and activity = "exit"
);
-- id     | name      | phone_number   | passport_number | license_plate
-- 221103 | Patrick   | (725) 555-4692 | 2963008352      | 5P2BI95
-- 243696 | Amber     | (301) 555-4174 | 7526138472      | 6P58WS2
-- 396669 | Elizabeth | (829) 555-5269 | 7049073643      | L93JTIZ
-- 398010 | Roger     | (130) 555-0289 | 1695452385      | G412CB7
-- 449774 | Madison   | (286) 555-6063 | 1988161715      | 1106N58
-- 467400 | Danielle  | (389) 555-5198 | 8496433585      | 4328GD8
-- 514354 | Russell   | (770) 555-1861 | 3592750733      | 322W7JE
-- 560886 | Evelyn    | (499) 555-9472 | 8294398571      | 0NTHK55
-- 686048 | Ernest    | (367) 555-5533 | 5773159633      | 94KL13X


-- Get caller
select *
from people
where phone_number IN (
    select caller
    from phone_calls
    where year = 2020
        and month = 7
        and day = 28
        and duration < 60
);

-- Get airport id
select id from airports where city = "Fiftyville";

-- Theives went to city with airport id 4 and where on passenger manifesto for flight 36
select *
from people
where passport_number IN (
    select passport_number
    from passengers
    where flight_id = (
        select id
        from flights
        where origin_airport_id = (select id from airports where city = "Fiftyville")
            and year = 2020
            and month = 7
            and day = 29
        order by hour asc, minute asc
        limit 1
    )
);


-- Get thief
select people.*
from people
inner join (
    select id
    from people
    where id IN (
        select person_id
        from bank_accounts
        where account_number IN (
            select account_number
            from atm_transactions
            where year = 2020
                and month = 7
                and day = 28
                and atm_location = "Fifer Street"
                and transaction_type = "withdraw"
        )
    )
) as atm_people
    on people.id = atm_people.id
inner join (
    select id
    from people
    where license_plate IN (
        select license_plate
        from courthouse_security_logs
        where year = 2020
            and month = 7
            and day = 28
            and hour = 10
            and activity = "exit"
    )
) as pl_people
    on people.id = pl_people.id
inner join (
    select id
    from people
    where phone_number IN (
        select caller
        from phone_calls
        where year = 2020
            and month = 7
            and day = 28
            and duration < 60
    )
) as caller
    on people.id = caller.id
inner join (
    select id
    from people
    where passport_number IN (
        select passport_number
        from passengers
        where flight_id = (
            select id
            from flights
            where origin_airport_id = (select id from airports where city = "Fiftyville")
                and year = 2020
                and month = 7
                and day = 29
            order by hour asc, minute asc
            limit 1
        )
    )
) as pass
    on people.id = pass.id
order by name desc;

-- id     | name    | phone_number   | passport_number | license_plate
-- 449774 | Madison | (286) 555-6063 | 1988161715      | 1106N58
-- 686048 | Ernest  | (367) 555-5533 | 5773159633      | 94KL13X


-- Get people with whom they talked
select *
from phone_calls
where year = 2020
    and month = 7
    and day = 28
    and duration < 60;
-- id  | caller         | receiver       | year | month | day | duration
-- 233 | (367) 555-5533 | (375) 555-8161 | 2020 | 7     | 28  | 45
-- 254 | (286) 555-6063 | (676) 555-6554 | 2020 | 7     | 28  | 43

-- Find person with phone number (375) 555-8161...is he/she in the passenger manifesto?
select *
from people
where phone_number = "(375) 555-8161";
-- id     | name     | phone_number   | passport_number | license_plate
-- 864400 | Berthold | (375) 555-8161 |                 | 4V16VO0

-- Find person with phone number (676) 555-6554...is he/she in passenger manifesto?
select *
from people
where phone_number = "(676) 555-6554";
-- id     | name  | phone_number   | passport_number | license_plate
-- 250277 | James | (676) 555-6554 | 2438825627      | Q13SVG6

--36
select *
from passengers
where flight_id = 36;


select *
from airports
where id = 4;
-- id | abbreviation | full_name        | city
-- 4  | LHR          | Heathrow Airport | London


-- Thieves talked to each other on the phone and planed to take a flight out of town (flight 36 to from airpot 8 to aiport 4)
-- look for pairs in phone calls who where also on the passenger manifesto

-- pairs of people
select *
from phone_calls
where year = 2020
    and month = 7
    and day = 28
    and duration <= 60;


select people.*
from people
where phone_number IN (
    select caller
    from phone_calls
    where year = 2020
        and month = 7
        and day = 28
        and duration <= 60
) OR phone_number IN (
    select receiver
    from phone_calls
    where year = 2020
        and month = 7
        and day = 28
        and duration <= 60
);

select
    /* caller - thief */
    pca.name as caller_name
    --, pc.caller as caller_number
    , pca.passport_number as caller_passport

    /* receiver - accomplice */
    , pre.name as receiver_name
    --, pc.receiver as receiver_number
    , pre.passport_number as receiver_passport
from phone_calls AS pc
left join people AS pca
    on pc.caller = pca.phone_number
left join people as pre
    on pc.receiver = pre.phone_number
where year = 2020
    and month = 7
    and day = 28
    and duration <= 60;

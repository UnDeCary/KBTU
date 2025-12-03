

CREATE FUNCTION calculate_discount(original_price NUMERIC, discount_percent NUMERIC)
RETURNS NUMERIC
LANGUAGE plpgsql
AS $$
BEGIN
    RETURN original_price - (original_price * discount_percent/100);
END;
$$;

SELECT calculate_discount(100, 15);
SELECT calculate_discount(250.50, 20);

-- p2

CREATE FUNCTION film_stats(p_rating VARCHAR, OUT total_films INT, OUT avg_rental_rate NUMERIC)
LANGUAGE plpgsql
AS $$
BEGIN
    SELECT
        count(*), avg(rental_rate)
    INTO total_films, avg_rental_rate
    FROM film
    WHERE rating = p_rating;
END;
$$;

CREATE FUNCTION get_customer_rentals(
    p_customer_id INT
)
RETURNS TABLE (
                  rental_date DATE,
                  film_title VARCHAR,
                  return_date DATE
              )
LANGUAGE plpgsql
AS $$
BEGIN
    RETURN QUERY
    SELECT
        rental_date,
        film_title,
        return_date
    FROM rental
    LEFT JOIN projects USING (dept_id);
end;
    $$;



-- =====================================================================================================================
-- =================================================== In-Class Task ===================================================
-- =====================================================================================================================

-- ================================================== Database Setup ===================================================

CREATE TABLE drivers (
    driver_id SERIAL PRIMARY KEY,
    full_name VARCHAR(100),
    phone VARCHAR(20),
    license_number VARCHAR(20),
    vehicle_type VARCHAR(30),
    rating NUMERIC(2,1),
    total_trips INTEGER,
    registration_date DATE
);

INSERT INTO drivers (full_name, phone, license_number, vehicle_type, rating, total_trips,
                     registration_date) VALUES
    ('Ержан Мұратов', '+77011234567', 'AA 1234567', 'Comfort', 4.8, 1245, '2022-01-15'),
    ('Айгерім Сәбитова', '+77012345678', 'AA 2345678', 'Economy', 4.9, 2103, '2021-06-20'),
    ('Бекзат Нұрланов', '+77023456789', 'AA 3456789', 'Business', 4.7, 856, '2022-09-10'),
    ('Гүлнар Қасымова', '+77034567890', 'AA 4567890', 'Comfort', 4.6, 1567, '2021-11-05'),
    ('Дәулет Төлеуов', '+77045678901', 'AA 5678901', 'Economy', 4.8, 2456, '2021-03-22'),
    ('Жанар Әміржанова', '+77056789012', 'AA 6789012', 'Premium', 4.9, 678, '2023-01-10'),
    ('Мәди Сериков', '+77067890123', 'AA 7890123', 'Comfort', 4.5, 1890, '2022-05-18'),
    ('Сәуле Бақытқызы', '+77078901234', 'AA 8901234', 'Economy', 4.7, 2234, '2021-08-30');


CREATE TABLE passengers (
    passenger_id SERIAL PRIMARY KEY,
    full_name VARCHAR(100),
    phone VARCHAR(20),
    email VARCHAR(100),
    registration_date DATE,
    preferred_payment VARCHAR(20),
    loyalty_level VARCHAR(20)
);

INSERT INTO passengers (full_name, phone, email, registration_date, preferred_payment,
                        loyalty_level) VALUES
    ('Асель Нұрғожина', '+77711234567', 'asel.n@mail.kz', '2023-01-10', 'card', 'gold'),
    ('Тимур Жақсылықов', '+77722345678', 'timur.zh@gmail.com', '2023-02-15', 'kaspi', 'silver'),
    ('Динара Әбдіқадырова', '+77733456789', 'dinara.a@inbox.kz', '2022-11-20', 'cash', 'bronze'),
    ('Нұрлан Есімов', '+77744567890', 'nurlan.e@mail.kz', '2023-03-05', 'card', 'platinum'),
    ('Балжан Қайратқызы', '+77755678901', 'balzhan.k@gmail.com', '2022-08-15', 'kaspi', 'gold'),
    ('Ернар Мұхамедов', '+77766789012', 'ernar.m@inbox.kz', '2023-04-20', 'card', 'silver'),
    ('Айым Төлеуова', '+77777890123', 'aiym.t@mail.kz', '2023-05-12', 'kaspi', 'bronze'),
    ('Қуаныш Бектемір', '+77788901234', 'kuanysh.b@gmail.com', '2022-12-01', 'card', 'platinum');


CREATE TABLE trips (
    trip_id SERIAL PRIMARY KEY,
    driver_id INTEGER REFERENCES drivers(driver_id),
    passenger_id INTEGER REFERENCES passengers(passenger_id),
    pickup_location VARCHAR(200),
    dropoff_location VARCHAR(200),
    distance_km NUMERIC(6,2),
    duration_minutes INTEGER,
    base_fare NUMERIC(10,2),
    surge_multiplier NUMERIC(3,2),
    total_fare NUMERIC(10,2),
    trip_date TIMESTAMP,
    status VARCHAR(20),
    payment_method VARCHAR(20)
);

INSERT INTO trips (driver_id, passenger_id, pickup_location, dropoff_location, distance_km,
                   duration_minutes, base_fare, surge_multiplier, total_fare, trip_date, status, payment_method)
VALUES
    (1, 1, 'Almaty, Dostyk Ave 120', 'Almaty, Abai Ave 45', 8.5, 25, 1200, 1.0, 1200, '2024-11-15
08:30:00', 'completed', 'card'),
    (2, 2, 'Almaty, Furmanov 89', 'Almaty, Satpaev 150', 12.3, 35, 1500, 1.2, 1800, '2024-11-15
09:15:00', 'completed', 'kaspi'),
    (3, 3, 'Astana, Kabanbay Batyr 12', 'Astana, Mangilik El 55', 15.7, 40, 2000, 1.0, 2000, '2024-11-15
10:00:00', 'completed', 'cash'),
    (1, 4, 'Almaty, Zhibek Zholy 45', 'Almaty Airport', 25.4, 50, 3500, 1.5, 5250, '2024-11-15 14:20:00',
     'completed', 'card'),
    (4, 5, 'Almaty, Rozybakiev 123', 'Almaty, Timiryazev 89', 6.2, 18, 900, 1.0, 900, '2024-11-15
15:45:00', 'completed', 'kaspi'),
    (5, 6, 'Shymkent, Baidibek Bi 34', 'Shymkent, Tauke Khan 78', 9.8, 28, 1300, 1.1, 1430, '2024-11-15
16:30:00', 'completed', 'card'),
    (6, 7, 'Almaty, Al-Farabi 77', 'Almaty, Nauryzbai Batyr 120', 18.9, 45, 2500, 1.3, 3250, '2024-11-15
17:00:00', 'completed', 'kaspi'),
    (7, 8, 'Karaganda, Bukhar Zhyrau 56', 'Karaganda, Gogol 34', 7.4, 22, 1100, 1.0, 1100, '2024-11-15
18:15:00', 'completed', 'card'),
    (2, 1, 'Almaty, Abai Ave 45', 'Almaty, Dostyk Ave 120', 8.5, 24, 1200, 1.0, 1200, '2024-11-16
09:00:00', 'completed', 'card'),
    (1, 2, 'Almaty, Satpaev 150', 'Almaty, Republic Square', 10.5, 30, 1400, 1.0, 1400, '2024-11-16
10:30:00', 'completed', 'kaspi'),
    (3, 4, 'Astana, Esil District', 'Astana, Baiterek', 11.2, 32, 1500, 1.2, 1800, '2024-11-16 11:45:00',
     'completed', 'card'),
    (4, 3, 'Almaty, Medeu District', 'Shymbulak', 22.3, 55, 3000, 1.4, 4200, '2024-11-16 13:00:00',
     'completed', 'cash'),
    (5, 5, 'Almaty, Mega Center', 'Almaty, Dostyk Plaza', 5.8, 15, 850, 1.0, 850, '2024-11-16 14:20:00',
     'completed', 'kaspi');

CREATE TABLE promotions (
                            promo_id SERIAL PRIMARY KEY,
                            promo_code VARCHAR(20),
                            discount_percent NUMERIC(5,2),
                            max_discount NUMERIC(10,2),
                            min_trip_amount NUMERIC(10,2),
                            valid_from DATE,
                            valid_until DATE,
                            usage_limit INTEGER,
                            times_used INTEGER
);
-- Insert sample data
INSERT INTO promotions (promo_code, discount_percent, max_discount, min_trip_amount,
                        valid_from, valid_until, usage_limit, times_used) VALUES
                                                                              ('WINTER2024', 15.0, 2000, 1000, '2024-11-01', '2024-12-31', 1000, 234),
                                                                              ('NEWUSER', 25.0, 1500, 500, '2024-01-01', '2024-12-31', 5000, 1567),
                                                                              ('WEEKEND', 10.0, 1000, 800, '2024-11-01', '2024-11-30', 2000, 456),
                                                                              ('AIRPORT', 20.0, 3000, 2000, '2024-11-01', '2024-12-31', 500, 123);
-- Create driver_shifts table
CREATE TABLE driver_shifts (
                               shift_id SERIAL PRIMARY KEY,
                               driver_id INTEGER REFERENCES drivers(driver_id),
                               shift_date DATE,
                               start_time TIME,
                               end_time TIME,
                               total_hours NUMERIC(4,2),
                               trips_completed INTEGER,
                               earnings NUMERIC(10,2)
);
-- Insert sample data
INSERT INTO driver_shifts (driver_id, shift_date, start_time, end_time, total_hours,
                           trips_completed, earnings) VALUES
    (1, '2024-11-15', '08:00', '18:00', 10.0, 8, 15500),
    (2, '2024-11-15', '07:00', '16:00', 9.0, 12, 18900),
    (3, '2024-11-15', '10:00', '20:00', 10.0, 7, 14200),
    (4, '2024-11-15', '09:00', '17:00', 8.0, 6, 11800),
    (5, '2024-11-15', '08:30', '19:30', 11.0, 14, 21400),
    (1, '2024-11-16', '08:00', '18:00', 10.0, 9, 16800),
    (2, '2024-11-16', '07:00', '16:00', 9.0, 11, 17500);


-- ======================================== Task 1: Fare Calculation Functions =========================================

-- Excercise 1.1

CREATE FUNCTION calculate_trip_fare(
    distance_km NUMERIC,
    duration_minutes INT,
    vehicle_type VARCHAR
)
RETURNS NUMERIC
LANGUAGE plpgsql
AS $$
BEGIN
    RETURN max(distance_km * CASE
        WHEN vehicle_type = 'Economy' THEN 100
        WHEN vehicle_type = 'Comfort' THEN 150
        WHEN vehicle_type = 'Business' THEN 200
        WHEN vehicle_type = 'Premium' THEN 300
        END + duration_minutes * CASE
                WHEN vehicle_type = 'Economy' THEN 30
                WHEN vehicle_type = 'Comfort' THEN 40
                WHEN vehicle_type = 'Business' THEN 50
                WHEN vehicle_type = 'Premium' THEN 70
           END);
end;
$$;

SELECT calculate_trip_fare(10.0, 25, 'Economy');
SELECT calculate_trip_fare(2.0, 8, 'Comfort');
SELECT calculate_trip_fare(15.5, 35, 'Premium');

-- Exercise 1.2

CREATE FUNCTION calculate_surge_multiplier(
    trip_hour INT,
    trip_day INT,
    current_demand INT DEFAULT 50
)
RETURNS NUMERIC
LANGUAGE plpgsql
AS $$
BEGIN
    RETURN (1.0 +
            CASE
                WHEN trip_hour BETWEEN 7 AND 9 THEN 0.3
                WHEN trip_hour BETWEEN 17 AND 19 THEN 0.3
                ELSE 0.0
                END +
            CASE
                WHEN trip_day IN (0, 6) THEN 0.2
                ELSE 0.0
                END +
            CASE
                WHEN current_demand > 150 THEN 0.8
                WHEN current_demand > 100 THEN 0.5
                ELSE 0.0
                END
        );
end;
$$;

SELECT calculate_surge_multiplier(8, 1, 50);
SELECT calculate_surge_multiplier(20, 6, 120);
SELECT calculate_surge_multiplier(14, 3, 40);


-- ====================================================== Task 2 =======================================================

-- Exercise 2.1

CREATE FUNCTION driver_performance_summary(
    p_driver_id INT,
    OUT total_tripsz INT,
    OUT total_distance NUMERIC,
    OUT total_earnings NUMERIC,
    OUT avg_rating NUMERIC,
    OUT avg_fare_per_km NUMERIC
)
LANGUAGE plpgsql
AS $$
BEGIN
    SELECT driver_id, count(*), sum(distance_km), sum(total_fare), avg(rating), sum(total_fare)/sum(distance_km)
    INTO p_driver_id, total_tripsz, total_distance, total_earnings, avg_rating
    FROM trips
    LEFT JOIN drivers USING (driver_id)
    WHERE driver_id = p_driver_id
    GROUP BY driver_id;
end;
$$;


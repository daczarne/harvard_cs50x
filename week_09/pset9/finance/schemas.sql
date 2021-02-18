CREATE TABLE users (
    id INTEGER
    , username TEXT NOT NULL
    , hash TEXT NOT NULL
    , cash NUMERIC NOT NULL DEFAULT 10000.00
    , PRIMARY KEY(id)
);
CREATE UNIQUE INDEX username ON users (username);

CREATE TABLE portfolios (
    user_id INTEGER NOT NULL
    , asset_symbol TEXT NOT NULL
    , asset_name TEXT NOT NULL
    , asset_qty INTEGER NOT NULL
);
--CREATE UNIQUE INDEX portfolios_user_id ON portfolios (user_id);

CREATE TABLE transactions (
    user_id INTEGER NOT NULL
    , asset_symbol TEXT NOT NULL
    , asset_name TEXT NOT NULL
    , asset_qty INTEGER NOT NULL
    , asset_price NUMERIC NOT NULL
    , timestamp DATETIME DEFAULT CURRENT_TIMESTAMP
);
--CREATE UNIQUE INDEX transactions_user_id ON transactions (user_id);

--UPDATE users SET cash = 10000 WHERE id = 1;
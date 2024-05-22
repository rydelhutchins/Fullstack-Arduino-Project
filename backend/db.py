import os
from databases import Database

DATABASE_URL = os.getenv('DATABASE_URL', 'postgresql://nohax:hackmebitch!@localhost:5432/nohaxdb')

database = Database(DATABASE_URL)

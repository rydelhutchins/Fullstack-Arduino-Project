from databases import Database
import sqlalchemy
from sqlalchemy import create_engine, MetaData

DATABASE_URL = "postgresql://nohax:hackmebitch!@postgres:5432/nohaxdb"

database = Database(DATABASE_URL)
metadata = MetaData()

engine = create_engine(DATABASE_URL)
metadata.create_all(engine)

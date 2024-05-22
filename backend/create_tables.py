from sqlalchemy import create_engine, MetaData, Table, Column, Integer

DATABASE_URL = "postgresql://nohax:hackmebitch!@localhost:5432/nohaxdb"

engine = create_engine(DATABASE_URL)
metadata = MetaData()

led_state = Table(
    'led_state', metadata,
    Column('id', Integer, primary_key=True),
    Column('state', Integer, nullable=False),
)

metadata.create_all(engine)

import { connect } from "mongoose";

(async () => {
  try {
    const db = await connect("mongodb+srv://waders:waders123@dbwaders.g93n4z3.mongodb.net/test");
    console.log("DB is connected to", db.connection.name);
  } catch (error) {
    console.error(error);
  }
})();

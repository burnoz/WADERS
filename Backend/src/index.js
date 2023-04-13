import express from "express";
import indexRoutes from "./routes/index.routes.js";
import app from "./app.js";
import "./database.js";

app.listen(3000);
console.log("Server is running on port 3000");

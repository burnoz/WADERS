import { Router } from "express";
import Task from "../models/task.js"

const router = Router();

router.get("/", (req, res) => {
    res.render("index");
});

router.get("/data", async (req, res) => {
    const tasks = await Task.find().lean();
    console.log(tasks);
    res.render("data", { tasks: tasks });
});

export default router;

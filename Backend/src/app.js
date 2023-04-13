import express from "express";
import exphbs from "express-handlebars";
import indexRoutes from "./routes/index.routes.js";
import "./database.js";
import path from 'path';
const __dirname = path.resolve();


const app = express();

app.set('views', path.join(__dirname, 'src/views'));
app.engine('.hbs', exphbs.engine({ extname: '.hbs', defaultLayout: "main", layoutsDir: path.join(app.get('views'), 'layouts') }));

app.set('view engine', '.hbs');

app.use(indexRoutes);

app.use(express.static(path.join('src/public')));

export default app;
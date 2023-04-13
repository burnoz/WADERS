import {Schema, model} from 'mongoose';

// const taskSchema = new Schema({
//     title: String,
//     description: String,
//     done: Boolean,
//  }, {
//     timestamps: true,
// });

const maquinaSchema = new Schema({
    id: String,
    litros_d: Int32Array,
    litros_r: Int32Array,
    clientes_t: Int32Array,
    clientes_d: Int32Array,
    estado: String,
    liquido: String
}, {
    timestamps: true,
});

// export default model('Task', taskSchema);
export default model('maquina', maquinaSchema);
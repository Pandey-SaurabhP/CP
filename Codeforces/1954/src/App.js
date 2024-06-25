import "./App.css";
import { useState } from "react";
import { BrowserRouter, Routes, Route } from 'react-router-dom';

import Login from "./components/login";
import Dashboard from "./components/dashboard";
import Verify from "./components/verify";
import Common from "./components/common";

function App() {
    return (
        <div className="App">
            <BrowserRouter>
                <Routes>
                    <Route path="/" element={<Login />} />
                    <Route path="/dashboard" element={<Dashboard />} />
                    <Route path="/verify" element={<Verify />} />
                    <Route path="/common" element={<Common />} />
                </Routes>
            </BrowserRouter>
        </div>
    );
}

export default App;
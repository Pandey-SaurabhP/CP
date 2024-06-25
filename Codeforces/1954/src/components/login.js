import React, { useState } from 'react';
import axios from 'axios';
import { useNavigate } from 'react-router-dom';
import './login.css';

function Login() {
    const [username, setUsername] = useState('');
    const [password, setPassword] = useState('');
    const [message, setMessage] = useState('');
    const navigate = useNavigate();

    const handleSubmit = async (e) => {
        e.preventDefault();
        try {
            const response = await axios.post('http://localhost:3001/login', { username, password });
            if (response.data.success) {
                setMessage(response.data.message);
                // Pass the username data to the '/common' route
                // await axios.post('http://localhost:3001/common', { username });
                navigate('/common', { state: { username } });
            } else {
                setMessage(response.data.message);
            }
        } catch (error) {
            console.error(error);
            setMessage('Error logging in');
        }
    };

    const handleSignup = async (e) => {
        e.preventDefault();
        try {
            const response = await axios.post('http://localhost:3001/signup', { username, password });
            if (response.data.success) {
                setMessage(response.data.message);
                // Automatically login after signup
                await handleSubmit(e);
            } else {
                setMessage(response.data.message);
            }
        } catch (error) {
            console.error(error);
            setMessage('Error signing up');
        }
    };

    return (
        <div className="login-container">
            <h2>Login Page</h2>
            <div className="form-container">
                <form onSubmit={handleSubmit}>
                    <input
                        type="text"
                        placeholder="Username"
                        value={username}
                        onChange={(e) => setUsername(e.target.value)}
                    />
                    <br />
                    <input
                        type="password"
                        placeholder="Password"
                        value={password}
                        onChange={(e) => setPassword(e.target.value)}
                    />
                    <br />
                    <button type="submit">Login</button>
                </form>
            </div>
            <div className="form-container">
                <h2>Sign Up</h2>
                <form onSubmit={handleSignup}>
                    <input
                        type="text"
                        placeholder="Username"
                        value={username}
                        onChange={(e) => setUsername(e.target.value)}
                    />
                    <br />
                    <input
                        type="password"
                        placeholder="Password"
                        value={password}
                        onChange={(e) => setPassword(e.target.value)}
                    />
                    <br />
                    <button type="submit">Sign Up</button>
                </form>
            </div>
            {message && <p className="message">{message}</p>}
        </div>
    );

}

export default Login;

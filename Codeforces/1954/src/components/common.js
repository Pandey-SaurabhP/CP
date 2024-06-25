import React, { useState, useEffect } from 'react';
import { useLocation } from 'react-router-dom';
import axios from 'axios';
import './dashboard.css';
import { useNavigate } from 'react-router-dom';

function Common() {
    const location = useLocation();
    const username = location.state && location.state.username;
    const [rooms, setRooms] = useState([]); // State to store the list of rooms with statuses
    const [selectedRoom, setSelectedRoom] = useState(''); // State to store the selected room
    const [messages, setMessages] = useState([]); // State to store messages in the selected room
    const [newMessage, setNewMessage] = useState(''); // State to store the new message
    const [newIssue, setNewIssue] = useState(''); // State to store the new issue
    const [isModalOpen, setIsModalOpen] = useState(false); // State to manage modal visibility
    const navigate = useNavigate();
    const [description, setDescription] = useState('No Issue Selected');


    const [searchQuery, setSearchQuery] = useState('');

    // Filter messages based on search query
    // const handleSearchInputChange = (event) => {
    //     setSearchQuery(event.target.value);
    // };

    // Filter pending issues based on search query
    // const filteredRooms = rooms.filter(issue =>
    //     console.log(rooms)
    //     rooms.rooms.toLowerCase().includes(searchQuery.toLowerCase())
    // );

    useEffect(() => {
        console.log(username);
        if (username) {
            fetchRooms();
        }
    }, [username]);

    const handleProfile = async (e) => {
        e.preventDefault();
        navigate('/dashboard', { state: { username } });
    };


    const fetchRooms = async () => {
        try {
            const response = await axios.get('http://localhost:3001/get_all_rooms');

            setRooms(response.data);
            console.log('sadasdas : ', response.data);
        } catch (error) {
            console.error('Error fetching rooms:', error);
        }
    };

    const fetchMessages = async (selectedRoom) => {
        try {
            const response = await axios.post('http://localhost:3001/fetch_messages', { room: selectedRoom });
            const newMessages = response.data.map(message => ({
                author: message.author,
                time: message.time,
                message: message.message
            }));
            setMessages(newMessages);
        } catch (error) {
            console.error('Error fetching messages:', error);
        }
    };

    const handleRoomSelect = (room) => {
        fetchIssueDescription(room);
        setSelectedRoom(room);
        fetchMessages(room);
    };

    const handleNewMessageChange = (event) => {
        setNewMessage(event.target.value);
    };

    const handleAddMessage = async () => {
        try {
            await axios.post('http://localhost:3001/add_message', {
                room: selectedRoom,
                author: username,
                message: newMessage
            });
            fetchMessages(selectedRoom);
            setNewMessage('');
        } catch (error) {
            console.error('Error adding message:', error);
        }
    };

    const fetchIssueDescription = async (selectedRoom) => {
        try {
            const response = await axios.post('http://localhost:3001/get_message', { query: selectedRoom });
            console.log(response.data);
            setDescription(response.data);
            // setMessages(newMessages);
        } catch (error) {
            console.error('Error fetching messages:', error);
        }
    };

    const handleNewIssueChange = (event) => {
        setNewIssue(event.target.value);
    };

    const handleAddIssue = () => {
        setIsModalOpen(true); // Open the modal
    };

    // const handleCloseModal = () => {
    //     setIsModalOpen(false); // Close the modal
    // };

    // const [searchQuery, setSearchQuery] = useState(''); // State to store the search query

    // Function to handle search input change
    // const handleSearchInputChange = (event) => {
    //     setSearchQuery(event.target.value);
    // };

    // Filter rooms based on search query
    // Filter rooms based on search query
    // const filteredRooms = rooms.filter(room => {
    //     console.log("room.room_id:", room.room_id);
    //     console.log("searchQuery:", searchQuery);
    //     return room.room_id && room.room_id.toLowerCase().includes(searchQuery.toLowerCase());
    // });


    // console.log(filteredRooms);

    const handleIssueFormSubmit = async () => {
        try {
            const response = await axios.post('http://localhost:3001/add_issue', {
                author: username,
                issue: newIssue,
                status: "Active"
            });

            console.log('Rsp : ', response.config.data);

            if (response.data.success) {
                fetchRooms();
                setNewIssue('');
                setIsModalOpen(false); // Close the modal after successful submission
            }
        } catch (error) {
            console.error('Error adding issue:', error);
        }
    };

    return (
        <div className="dashboard-container">
            <button onClick={handleProfile} className="message-button">Profile</button>

            <div>
                {username && <p className='login-text'>Logged In as, {username}</p>}

                <div className="rooms-container">

                    {/* <input
                        type="text"
                        placeholder="Search by Room ID..."
                        value={searchQuery}
                        onChange={handleSearchInputChange}
                    /> */}

                    <ul className="room-list">
                        <br />
                        {rooms.map((room, index) => (
                            <li key={index} className="room" onClick={() => handleRoomSelect(room.room)}>
                                {room.room} - Status: {room.status}
                            </li>
                        ))}
                    </ul>
                </div>
            </div>

            <div className="messages-container">
                <h2>Issue ID - {selectedRoom}</h2>
                <h2>Message - {description}</h2>
                <ul className="message-list">
                    {messages && messages.map((message, index) => (
                        <li key={index} className="message">
                            <p className="message-text">{message.message}</p>
                            <div>
                                <span className="message-author">Sent by {message.author}</span>
                                <span className="message-time">{message.time}</span>
                            </div>
                        </li>
                    ))}
                </ul>

                <div className="new-message-container">
                    <input
                        type="text"
                        placeholder="Type your message..."
                        value={newMessage}
                        onChange={handleNewMessageChange}
                        className="message-input"
                    />
                    <button onClick={handleAddMessage} className="message-button">Add Message</button>
                </div>
            </div>

        </div>
    );

}

export default Common;
